groups $FT_USER | tr -d '\n' | sed 's/ /,/g' | sed 's/:/,/g' | sed 's/,,/,/g' | sed 's/,$//'
