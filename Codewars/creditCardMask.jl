function maskify(cc)

    if length(cc) < 5
      return cc;
    end
    ans = ""
    ans = repeat('#', length(cc) - 4)
    last = cc[end-3:end]
    return ans * last
    
  end