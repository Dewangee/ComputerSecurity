import datetime
import hashlib


#generates the hash value of a string via sha256() of hashlib
def genererateHASH(string):
    lib = hashlib.sha256()
    lib.update(string.encode())
    H = lib.hexdigest()
    return H

#This function returns the reverse of a string
def reverseOTP(string):
    return string[::-1]

#This function gives the final OTP based on the initial hash value
def F(H):

    for i in range(10):                             #For iterated hashing, we run the loop 10 times
        sum = 0
        for j in range(len(H)):                  #The hash value is iterated over
            sum += ord(H[j])                     #The sum of ascii values of all the characters is taken

        H = genererateHASH(reverseOTP(str(sum)))     #A new hash value is created by reversing the sum generated and providing it as input to SHA256

        if (i==9):                                     #The value is returned for the 10th iteration
            return reverseOTP(str(sum))


def main():
    file = [i for i in open("Hash.txt")]              #The hash value is read from a text file and stored in H
    H = str(file[0])
    O_new = F(H) ;                                     #The create OTP function gives the 4 digit required OTP O' for the value of H
    O = input("Enter OTP:")                           #The value of OTP is input by the user

    if (O==O_new):                                      #If the otp entered by the user is the same as the one generated through the hash function
        print("Successful")                             #The validation is successful
        file = open("Hash.txt", "w").write("")          #The hash value is removed from the file.
    else:
        print("Unsuccessful")                           #If the user entered an invalid OTP, the validation is unsuccessful

main()