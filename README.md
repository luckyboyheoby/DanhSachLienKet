# DANH SÁCH LIÊN KẾT (LINKED LISTS)

- Danh sách liên kết đơn (Single Linked List)
- Danh sách liên kết đôi (Double Linked List)
- Danh sách liên kết vòng (Circular Linked List)

------------

1. Kiểu dữ liệu tĩnh
Khái niệm: Một số đối tượng dữ liệu không thay thay đổi được kích thước, cấu trúc, … trong suốt quá trình sống. Các đối tượng dữ liệu này thuộc những kiểu dữ liệu tĩnh. 
Một số kiểu dữ liệu tĩnh: các cấu trúc dữ liệu được xây dựng từ các kiểu cơ sở như: kiểu thực, kiểu nguyên, kiểu ký tự … hoặc từ các cấu trúc đơn giản như cấu trúc, tập hợp, mảng.
> Các đối tượng dữ liệu thuộc kiểu dữ liệu tĩnh thường cứng ngắt, gò bó, khó diễn tả được thực tế vốn  sinh động, phong phú.

 Hạn chế của CTDL tĩnh
Một số đối tượng dữ liệu có thể thay đổi về cấu trúc, độ lớn… chẳng hạn danh sách các học viên trong một lớp học có thể tăng thêm, giảm đi...
<br>Nếu dùng những cấu trúc dữ liệu tĩnh đã biết như mảng để biểu diễn thì:
- Những thao tác phức tạp, kém tự nhiên
- Chương trình khó đọc, khó bảo trì
- Sử dụng bộ nhớ không hiệu quả( do dữ liệu tĩnh sẽ chiếm vùng nhớ đã dành cho chúng suốt quá trình hoạt động của chương trình )

<br>Cấu trúc dữ liệu tĩnh: Ví dụ: Mảng 1 chiều
- Kích thước cố định (fixed size)
- Chèn 1 phần tử vào mảng rất khó
- Các phần tử tuần tự theo chỉ số 0 đến n-1
- Truy cập ngẫu nhiên (random access)
[![Thao tác trên mảng](./images/thaoTacTrenMang.png "Thao tác trên mảng")](# "Thao tác trên mảng")

**Hướng giải quyết**
Cần xây dựng cấu trúc dữ liệu đáp ứng được các yêu cầu:
- Linh động hơn
- Có thể thay đổi kích thước, cấu trúc trong suốt thời gian sống
**->Cấu trúc dữ liệu động**

Cấu trúc dữ liệu động:
Ví dụ: Danh sách liên kết, cây
- Cấp phát động lúc chạy chương trình
- Các phần tử nằm rải rác ở nhiều nơi trong bộ nhớ
- Kích thước danh sách chỉ bị giới hạn do RAM
- Thao tác thêm xoá đơn giản

Tạo ra một biến động và cho con trỏ p chỉ đến nó:
```cpp
void* malloc(n*sizeof(kiểu_dữ_liệu));
```
// trả về con trỏ chỉ đến vùng nhớ size byte vừa được cấp phát.
```cpp
void* calloc(n, sizeof(kiểu_dữ_liệu));
```
// trả về con trỏ chỉ đến  vùng nhớ  vừa được cấp phát gồm n phần tử,
 // mỗi phần tử có kích thước size byte
```cpp
new kiểu_dữ_liệu[n]; // toán tử cấp phát bộ nhớ trong C++
```
Hàm free(p) huỷ vùng nhớ cấp phát bởi hàm malloc hoặc calloc do p trỏ tới
Toán tử delete[ ] p huỷ vùng nhớ cấp phát bởi toán tử new do p trỏ tới

**Danh sách liên kết:**
- Mỗi phần tử của danh sách gọi là node (nút)
- Mỗi node có 2 thành phần: phần dữ liệu và phần liên kết chứa địa chỉ của node kế tiếp hay node trước nó
- Các thao tác cơ bản trên danh sách liên kết:
Thêm một phần tử mới
Xóa một phần tử
Tìm kiếm
…
- Danh sách liên kết đơn: mỗi phần tử liên kết với phần tử đứng sau nó trong danh sách:
![Danh Sách Liên Kết Đơn](./images/dslkDon.png "Danh sách liên kết đơn")
- Danh sách liên kết đôi: mỗi phần tử liên kết với các phần tử đứng trước và sau nó trong danh sách:
[![Danh sách liên kết đôi](./images/dslkDoi.png "Danh sách liên kết đôi")](# "Danh sách liên kết đôi")
- Danh sách liên kết vòng : phần tử cuối danh sách liên kết với phần tử đầu danh sách:
[![Danh sách liên kết vòng](./images/dslkVong.png "Danh sách liên kết vòng")](# "Danh sách liên kết vòng")
# Danh sách liên kết đơn (DSLK đơn)
Là danh sách các node mà mỗi node có 2 thành phần:
- Thành phần dữ liệu: lưu trữ các thông tin về bản thân phần tử
- Thành phần mối liên kết: lưu trữ  địa chỉ của phần tử kế tiếp trong danh sách, hoặc lưu trữ giá trị NULL nếu là phần tử cuối danh sách
Khai báo node
```cpp
struct  Node {
		DataType data; // DataType là kiểu đã định nghĩa trước
		Node *pNext;   // con trỏ chỉ đến cấu trúc Node
};
```
Cấu trúc 1 node
[![Cấu trúc node](./images/aNode.png "Cấu trúc node")](# "Cấu trúc node")

Ví dụ 1: Khai báo node lưu số nguyên:
```cpp
struct  Node {
		int data;
		Node *pNext; 
};
```
Ví dụ 2: Định nghĩa một phần tử trong danh sách đơn lưu trữ hồ sơ sinh viên:
```cpp
struct SinhVien {
		char Ten[30];
		int MaSV;
};
struct SVNode {
		SinhVien data;
		SVNode *pNext;
};
```
Tổ chức, quản lý:
Để quản lý một DSLK đơn chỉ cần biết địa chỉ phần tử đầu danh sách
Con trỏ pHead sẽ được dùng để lưu trữ địa chỉ phần tử đầu danh sách. Ta có khai báo:
```cpp
Node *pHead;
```
Để tiện lợi, có thể sử dụng thêm  một con trỏ pTail giữ địa chỉ phần tử cuối danh sách. Khai báo pTail như sau: 
```cpp
Node *pTail;
```
[![Quản lí danh sách liên kết](./images/quanLiDSLK.png "Quản lí danh sách liên kết")](# "Quản lí danh sách liên kết")

Ví dụ: Khai báo cấu trúc 1 DSLK đơn chứa số nguyên
// kiểu của một phần tử trong danh sách
```cpp
struct Node {
	int data;
	Node* pNext;
};
// kiểu danh sách liên kết
struct List {
	Node* pHead;
	Node* pTail;
};
//Khai báo biến kiểu danh sách:
	List  tên_biến; //Danh sách của node

```
Tạo một node mới: Viết hàm getNode 
```cpp
Node* getNode ( DataType  x) {
	Node *p;
	p = new Node;  // Cấp phát vùng nhớ cho node
	if  (p==NULL) {
		cout<<“Khong du bo nho!”;  return NULL; 
	}
	p->data = x; 	// Gán dữ liệu cho phần tử p
	p->pNext = NULL;
	return p;
}
```
Để tạo một phần tử mới cho danh sách, cần thực hiện câu lệnh: 
```cpp
Node *new_ele = GetNode(x);
```
new_ele sẽ quản lý địa chỉ của phần tử mới được tạo.

Các thao tác cơ bản trên danh sách liên kết:
- Tạo danh sách rỗng
- Thêm một phần tử vào danh sách
- Duyệt danh sách
- Tìm kiếm một giá trị trên danh sách
- Xóa một phần tử ra khỏi danh sách
- Hủy toàn bộ danh sách
- …

Tạo danh sách rỗng
[![Tạo danh sách rỗng](./images/taoDanhSachRong.png "Tạo danh sách rỗng")](# "Tạo danh sách rỗng")
```cpp
void Init(List &L) {
	L.pHead = L.pTail = NULL;
}

```

Thêm một phần tử vào danh sách: Có 3 vị trí thêm
- Gắn vào đầu danh sách
- Gắn vào cuối danh sách 
- Chèn vào sau nút q trong danh sách
**Chú ý trường hợp danh sách ban đầu rỗng**
<br>**Thêm một phần tử**
Nếu danh sách (L) ban đầu **rỗng**
[![Thêm phần tử khi danh sách ban đầu rỗng](./images/themPhanTuDSRong.png "Thêm phần tử khi danh sách ban đầu rỗng")](# "Thêm phần tử khi danh sách ban đầu rỗng")
```cpp
L.pHead = L.pTail = new_node;
```
<br>**Thêm một phần tử**
Nếu danh sách (L) ban đầu **không rỗng:**
** 1. Gắn node vào đầu danh sách**
```cpp
new_node->pNext = L.pHead;
L.pHead = new_node;
```

    

    Thuật toán: Gắn nút vào đầu DS
    	// input: danh sách, phần tử mới new_node
    	// output: danh sách với new_node ở đầu DS
    Nếu DS rỗng thì
    	L.pHead = L.pTail = new_node;
    Ngược lại
    	new_node->pNext = L.pHead;
    	L.pHead = new_node;

Cài đặt: Gắn Node vào đầu danh sách
```cpp
void addHead(List &L, Node* new_node) {
	if (L.pHead == NULL)  // DS rỗng
	{
		L.pHead = L.pTail = new_node;
	}
	else
	{
		new_node->pNext = L.pHead;
		L.pHead = new_node;
	}
}
```
Thêm một thành phần dữ liệu vào đầu( Khi ta có data -> node -> thêm vào danh sách):
```cpp
void Insertfirst(LIST &L, datatype x) {
	NODE* new_node = GetNode(x);
	if (new_node == NULL)
		return;
	addHead(L, new_node);
}
```


    Thuật toán: Thêm một thành phần dữ liệu vào đầu DS
    	// input: danh sách l
    	// output: danh sách l với phần tử chứa X ở đầu DS
    Nhập dữ liệu cho X  (???)
    Tạo nút mới chứa dữ liệu X  (???)
    Nếu tạo được:
    Gắn nút mới vào đầu danh sách  (???)
    

Ví dụ: Thêm một số nguyên vào đầu ds:
	// Nhập dữ liệu cho X
	int x;
	cout<<“Nhap X=”;	cin>>x;
	// Tạo nút mới
	Node* new_node = GetNode(x);
	// Gắn nút vào đầu ds
	if (new_node != NULL) addHead(L, new_node);

Thêm một phần tử
Nếu danh sách (L)ban đầu **không rỗng**: 
** 2. Gắn node vào cuối danh sách:**
[![Thêm một phần tử vào cuối danh sách](./images/themPhanTuDSKoRongCuoiDS.png "Thêm một phần tử vào cuối danh sách")](# "Thêm một phần tử vào cuối danh sách")
```cpp
	L.pTail->pNext = new_node;
	L.pTail = new_node;
```



    Thuật toán: Thêm một phần tử vào cuối DS
    	// input: danh sách, phần tử mới new_node
    	// output: danh sách với new_node ở cuối DS
    Nếu DS rỗng thì
    	L.pHead = L.pTail = new_node;
    Ngược lại
    	L.pTail->pNext = new_node ;
    	L.pTail = new_node;
    

Cài đặt: Gắn nút vào cuối DS
```cpp
void addTail(List &L, Node *new_node) {
	if (L.pHead == NULL)
	{
		L.pHead = L.pTail = new_node;
	}
	else
	{
		L.pTail->pNext = new_node;
		L.pTail = new_node ;
	}
}

```

Thêm một thành phần dữ liệu vào cuối danh sách( Dữ liệu -> Node -> Thêm vào danh sách)
```cpp
void InsertLast(LIST &L, datatype x) {
	NODE* new_node = GetNode(x);
	if (new_node == NULL)
		return;
	addTail(L, new_node);
}
```

    Thuật toán: Thêm một thành phần dữ liệu vào cuối ds	
    	// input: danh sách thành phần dữ liệu X
    	// output: danh sách với phần tử chứa X ở cuối DS
    Nhập dữ liệu cho X  (???)
    Tạo nút mới chứa dữ liệu X (???)
    Nếu tạo được:
    Gắn nút mới vào cuối danh sách (???)

Ví dụ: Thêm một số nguyên vào cuối ds:
```cpp
// Nhập dữ liệu cho X
	int x;
	cout<<"Nhập X="; 	cin>>x;
	// Tạo nút mới
	Node* p = GetNode(x);
	// Gắn nút vào cuối DS
	if (p != NULL)	addTail(L, p);
```

Thêm một phần tử
** 3. Chèn vào sau nút q trong danh sách: **
**Chú ý trường hợp danh sách ban đầu rỗng**
Thêm một phần tử
Nếu danh sách ban đầu **rỗng**

[![Thêm phần tử ds rỗng](./images/themPhanTuSauNutQDSRong.png "Thêm phần tử sau nút Q")](# "Thêm phần tử sau nút Q")

```cpp
	L.pHead = L.pTail = new_node;
```
Chèn một phần tử sau q
[![Chèn một phần tử sau Q](./images/chenSauQ.png "Chèn một phần tử sau Q")](# "Chèn một phần tử sau Q")
```cpp
new_node->pNext = q->pNext;
q->pNext = new_node;

//Nếu q->pNext == NULL thì
	L.pTail = new_node
```
    Thuật toán: Chèn một phần tử sau q
    	// input: danh sách l, q, phần tử mới new_node
    	// output: danh sách với new_node ở sau q
    Nếu  (q != NULL) thì:
    new_node -> pNext = q -> pNext;
    q -> pNext = new_node ;
    Nếu  ( q == L.pTail) thì
    L.pTail = new_node;
    Ngược lại
    	Thêm new_node vào đầu danh sách
    

Cài đặt: Chèn một phần tử sau q
```cpp
void addAfter (List &L, Node *q, Node* new_node) {
	if (q!=NULL)
	{
		new_node->pNext = q->pNext;
		q->pNext = new_node;
		if(q == L.pTail)  	L.pTail = new_node;
	}
}
```
Thêm một thành phần dữ liệu vào cuối
```cpp
NODE* InsertAfter(LIST &L, NODE *q, data x) {
		NODE* p = GetNode(x);
		AddAfter(L, q, p);
}
```


    Thuật toán: Thêm một thành phần dữ liệu vào sau q	
    	// input: danh sách thành phần dữ liệu X
    	// output: danh sách với phần tử chứa X ở cuối DS
    Nhập dữ liệu cho nút q  (???)
    Tìm nút q (???)
    Nếu tồn tại q trong ds thì:
    Nhập dữ liệu cho X  (???)
    Tạo nút mới chứa dữ liệu X (???)
    Nếu tạo được:
    Gắn nút mới vào sau nút q   (???)
    Ngược lại thì báo lỗi
	
**Duyệt danh sách**
Là thao tác thường được thực hiện khi có nhu cầu xử lý các phần tử của danh sách theo cùng một cách thức hoặc khi cần lấy thông tin tổng hợp từ các phần tử của danh sách như:
Đếm các phần tử của danh sách
Tìm tất cả các phần tử thoả điều kiện
Hủy toàn bộ danh sách (và giải phóng bộ nhớ)
…
