<%@ Page Language="C#" AutoEventWireup="true" CodeFile="wind.aspx.cs" Inherits="wind" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            height: 23px;
            width: 209px;
        }
        .auto-style2 {
            width: 77px;
        }
        .auto-style3 {
            height: 23px;
            width: 77px;
        }
        .auto-style4 {
            width: 209px;
        }
    </style>
</head>
<body style="background-color:#F2F2F2">
    <form id="form1" runat="server">
    <div>
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="Label1" runat="server" Font-Size="25pt" ForeColor="#CC33FF" Text="请输入您的个人信息："></asp:Label>
        <br />
        <br />
        <br />
    <table style="width:400px; margin:auto;"">
        <tr>
            <td class="auto-style2">用户名：</td> <td class="auto-style4">
            <asp:TextBox ID="name" runat="server"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">昵称：</td> <td class="auto-style4">
            <asp:TextBox ID="rename" runat="server"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">性别：</td> <td class="auto-style4">
            <asp:DropDownList ID="sex" runat="server">
                <asp:ListItem Value="1">男</asp:ListItem>
                <asp:ListItem Value="0">女</asp:ListItem>
            </asp:DropDownList>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">邮箱：</td> <td class="auto-style4">
            <asp:TextBox ID="email" runat="server"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">电话：</td> <td class="auto-style4">
            <asp:TextBox ID="phone" runat="server"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">地址：</td> <td class="auto-style4">
            <asp:TextBox ID="address" runat="server"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style3">密码：</td> <td class="auto-style1">
            <asp:TextBox ID="password" runat="server"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">&nbsp;</td> <td class="auto-style4">
            <asp:Button ID="Button1" runat="server" Text="注册" Height="30px" OnClick="Button1_Click" Width="79px" />
            </td>
        </tr>
    </table>
    </div>
        <p>
            &nbsp;</p>
    </form>
</body>
</html>
