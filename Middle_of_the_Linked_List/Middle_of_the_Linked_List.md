### 快慢指针法
#### 偶数时，取后一个中间结点（如[1,2,3,4,5,6]，取4），fast移动至nullptr时停止
> fast!= nullptr对应偶数

> fast->next != nullptr对应奇数，fast移动至最后一个节点时停止
```c++
while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
}
```


#### 偶数时，取前一个中间结点（如[1,2,3,4,5,6]取3），fast移动至倒数第二个节点时停止
> fast->next->next != nullptr对应偶数

> fast->next != nullptr对应奇数，fast移动至最后一个节点时停止
```c++
 while (fast->next != nullptr && fast->next->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
 }
```

## 说明
循环条件分别对应了链表节点数为奇偶两种情况