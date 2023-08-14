print('Name : Bijay Regmi\nRegistration Number : 210913032\n')

from datetime import datetime
date_input = input("Enter Date (mm/dd/yyyy) : ")
date_object = datetime.strptime(date_input, '%m/%d/%Y')
print(date_object.strftime('%B %d, %Y'))