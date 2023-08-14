print('Name : Bijay Regmi\nRegistration Number : 210913032\n')

with open('7.txt') as f1:
    with open('7Output.txt', 'w') as f2:
        profiles = f1.readlines()
        for profile in profiles:
                name, email, phone = profile.split('        ')
                f2.write('        '.join([' '.join([s.capitalize() for s in name.split()]), email, '301-' + phone]))
                