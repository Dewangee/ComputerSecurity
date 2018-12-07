# Generated by Django 2.1.1 on 2018-10-24 01:38

from django.conf import settings
from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('app', '0030_auto_20181020_2341'),
    ]

    operations = [
        migrations.CreateModel(
            name='MerchantPaymentAccount',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('account', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='payment_account', to='app.Account')),
                ('merchant_user', models.ForeignKey(limit_choices_to={'user_type__in': 2}, on_delete=django.db.models.deletion.CASCADE, related_name='merchant_user', to=settings.AUTH_USER_MODEL)),
            ],
        ),
        migrations.AlterUniqueTogether(
            name='merchantpaymentaccount',
            unique_together={('merchant_user', 'account')},
        ),
    ]
