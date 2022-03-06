# def fakeAdd(x, y):
#   return x * y

import re
def clean_space(text):
    """"
    处理多余的空格
    """
    match_regex = re.compile(u'[\u4e00-\u9fa5。\.,，:：《》、\(\)（）]{1} +(?<![a-zA-Z])|\d+ +| +\d+|[a-z A-Z]+')
    should_replace_list = match_regex.findall(text)
    order_replace_list = sorted(should_replace_list,key=lambda i:len(i),reverse=True)
    for i in order_replace_list:
        if i == u' ':
            continue
        new_i = i.strip()
        text = text.replace(i,new_i)
    return text

# def clean_space_beforeChinese(text):

print(clean_space("input：我今天 赚了 10 个亿，老百姓very happy。"))


def powMod(x, n, M):
  r = 1
  while n:
    if (n & 1):
      r = r * x % M
    x = x * x % M
    n = n >> 1
  return r

print(powMod(10, 2, 13));
print(100 % 13);