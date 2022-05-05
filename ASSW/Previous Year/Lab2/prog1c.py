from datetime import datetime
date_input = input('Enter a date(mm/dd/yyyy): ')
date_object = datetime.strptime(date_input, '%m/%d/%Y')
print(date_object.strftime('%B %d, %Y'))
