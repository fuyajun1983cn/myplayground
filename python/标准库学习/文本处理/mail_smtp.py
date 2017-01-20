#!/usr/bin/env python2

from __future__ import print_function
import smtplib

mail_server = 'localhost'
mail_server_port = 25

to_addr = "fuyajun1983cn@163.com"
from_addr = "fuyajun1983cn@gmail.com"

from_header = "From: %s\r\n" % from_addr
to_header = "To: %s\r\n" % to_addr

subject_header = "Subject: nothing interesting"

body = "This is a not very interestring mail"

email_message = '%s\n%s\n%s\n\n%s' % (from_header, to_header, subject_header, body)

s = smtplib.SMTP(mail_server, mail_server_port)
s.set_debuglevel(1)
s.starttls()
s.login('fuyajun1983cn', '')
s.sendmail(from_addr, to_addr, email_message)
s.quit()
