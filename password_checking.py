password = input("Podaj nowe hasło: ")

longpass = len(password) >= 8
has_lower = False
has_upper = False
has_digit = False
for char in password:  # idź znak po znaku
    if char.isalpha() and char.isupper():
        has_upper = True
    if char.isalpha() and char.islower():
        has_lower = True
    if char.isdigit():
        has_digit = True

is_correct = has_lower and has_upper and has_digit and longpass
if is_correct:
    print("Twoje hasło jest wystarczająco złożone")
else:
    print("Zmień poniższe rzeczy w Twoim haśle:")
    if not has_lower:
        print("- przynajmniej jedna mała litera")
    if not has_upper:
        print("- przynajmniej jedna duża litera")
    if not has_digit:
        print("- przynajmniej jedna cyfra")
    if not longpass:
        print("- hasło musi mieć minimum 8 znaków")