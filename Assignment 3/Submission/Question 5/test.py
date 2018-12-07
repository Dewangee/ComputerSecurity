from _socket import inet_ntoa

import dpkt

if __name__ == '__main__':

    f = open('log.pcap', 'rb')              #Reading the pcap file
    pcap = dpkt.pcap.Reader(f)

    malicious_ip = []

    for ts, buf in pcap:
        eth = dpkt.ethernet.Ethernet(buf)       #Extraction of ethernet files
        if eth.type != dpkt.ethernet.ETH_TYPE_IP:       #If packet is not of IP type, it is not considered
            continue

        ip = eth.data

        if ip.p == dpkt.ip.IP_PROTO_TCP:        #If packet is not of TCP type, it is not considered (UDP not considered)
            tcp = ip.data
            if tcp.flags == 0x2:                    #Checking for SYN packets
                src = inet_ntoa(ip.src)
                if src not in malicious_ip:
                    malicious_ip.append(src)        #Storing distinct malicious IPs in a list

    print malicious_ip