<%@ Page Language="C#" AutoEventWireup="true" CodeFile="index.aspx.cs" Inherits="index" %>

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
<body style="background-color:#F2F2F2">
    <form id="form1" runat="server">
    <div style="text-align: center">
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="Label1" runat="server" Font-Size="25pt" ForeColor="#CC33FF" Text="欢迎来到在线挂号平台！"></asp:Label>
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
            <asp:Label ID="rename" runat="server" Height="16px" Width="128px"></asp:Label>
            </td>
        </tr>
        <tr>
            <td>性别：</td> <td>
            <asp:Label ID="sex" runat="server" Height="16px" Width="128px"></asp:Label>
            </td>
        </tr>
        <tr>
            <td>邮箱：</td> <td>
            <asp:Label ID="email" runat="server" Height="16px" Width="128px"></asp:Label>
            </td>
        </tr>
        <tr>
            <td class="auto-style1">电话：</td> <td class="auto-style1">
            <asp:Label ID="phone" runat="server" Height="16px" Width="128px"></asp:Label>
            </td>
        </tr>
        <tr>
            <td>地址：</td> <td>
            <asp:Label ID="address" runat="server" Height="16px" Width="128px"></asp:Label>
            </td>
        </tr>
        <tr>
            <td>密码：</td> <td>
            <asp:Label ID="password" runat="server" Height="16px" Width="128px"></asp:Label>
            </td>
        </tr>
        <tr>
            <td>
                <asp:HiddenField ID="HF" runat="server" />
            </td> <td>
                &nbsp;</td>
        </tr>
    </table>
        <asp:Button ID="Button1" runat="server" Text="开始挂号" Height="36px" Width="119px" OnClick="Button1_Click" />
        <br />
        <br />

    </div>
    </form>
</body>
</html>
