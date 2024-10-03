const isStrongPassword = (string) => {
  let regex = ^.*(?=.{8,})(?=.*[a-zA-Z])(?=.*\d)(?=.*[!#$%&? "]).*$
  return regex.test(string)
}
