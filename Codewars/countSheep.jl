function countsheep(num)
    ans = "";
    for i in 1:num
      ans = ans * string(i) * " sheep..."
    end
    return ans
  end