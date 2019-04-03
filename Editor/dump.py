with open('guts', 'wb') as guts:
    raw = input('Enter dump from editor: ')
    dump = None 
    exec('dump = b\'{}\''.format(raw))
    guts.write(dump)
