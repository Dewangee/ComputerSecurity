# Generated by Django 2.1.1 on 2018-10-10 19:25

from django.conf import settings
from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('app', '0012_auto_20181011_0051'),
    ]

    operations = [
        migrations.AlterField(
            model_name='transaction',
            name='from_account',
            field=models.ForeignKey(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, related_name='transaction_from', to='app.Account'),
        ),
        migrations.AlterField(
            model_name='transaction',
            name='to_account',
            field=models.ForeignKey(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, related_name='transaction_to', to='app.Account'),
        ),
        migrations.AlterField(
            model_name='userrequest',
            name='from_user',
            field=models.ForeignKey(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, related_name='request_from', to=settings.AUTH_USER_MODEL),
        ),
        migrations.AlterField(
            model_name='userrequest',
            name='to_user',
            field=models.ForeignKey(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, related_name='request_to', to=settings.AUTH_USER_MODEL),
        ),
    ]
