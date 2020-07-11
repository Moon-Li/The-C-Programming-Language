<%@ Page Language="C#" AutoEventWireup="true" CodeFile="upUser.aspx.cs" Inherits="upUser" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            height: 23px;
        }
    </style>
</head>
<body style="background-color:#66FFFF">
    <form id="form1" runat="server">
    <div>
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="Label1" runat="server" Font-Size="25pt" ForeColor="#CC33FF" Text="请修改信息："></asp:Label>
        <br />
        <br />

    <table style="width:400px; margin:auto;">
        <tr>
            <td class="auto-style1">用户名：</td> <td class="auto-style1">
            <asp:Label ID="name" runat="server" Height="16px" Width="128px"></asp:Label>
            </td>
        </tr>
        <tr>
            <td>昵称：</td> <td>
            <asp:TextBox ID="rename" runat="server"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td>性别：</td> <td>
            <asp:DropDownList ID="sex" runat="server">
                <asp:ListItem Value="1">男</asp:ListItem>
                <asp:ListItem Value="0">女</asp:ListItem>
            </asp:DropDownList>
            </td>
        </tr>
        <tr>
            <td>邮箱：</td> <td>
            <asp:TextBox ID="email" runat="server"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style1">电话：</td> <td class="auto-style1">
            <asp:TextBox ID="phone" runat="server"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td>地址：</td> <td>
            <asp:TextBox ID="address" runat="server"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td>密码：</td> <td>
            <asp:TextBox ID="password" runat="server"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td>
                <asp:HiddenField ID="HF" runat="server" OnValueChanged="HF_ValueChanged" />
            </td> <td>
            <asp:Button ID="Button1" runat="server" Text="保存" Height="30px" OnClick="Button1_Click" Width="79px" />
            </td>
        </tr>
    </table>
    </div>
    </form>
</body>
</html>
