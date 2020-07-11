<%@ Page Language="C#" AutoEventWireup="true" CodeFile="helloroot.aspx.cs" Inherits="helloroot" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body style="background-color:#F2F2F2">
    <form id="form1" runat="server">
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
        <br />
    <div style="text-align: center; height: 296px;">

    <asp:Label ID="Label1" runat="server" Font-Size="XX-Large" ForeColor="Black" Text="欢迎来到在线挂号平台"></asp:Label>
        <br />
        <br />
        <br />
        <asp:Label ID="Label2" runat="server" Text="请登录："></asp:Label>
        <br />
&nbsp;<table border="0" style="width: 396px; margin:auto; text-align:center; background-color: #F5F5F5;">
        <tr><td class="auto-style1">用户名</td><td class="auto-style4">
            <asp:Label ID="root" runat="server" Height="32px" Width="237px"></asp:Label>
            </td></tr>
        <tr><td class="auto-style1">密码</td><td class="auto-style4">
            <asp:TextBox ID="password" runat="server" Height="32px" Width="237px" TextMode="Password"></asp:TextBox>
            </td></tr>
    </table>
        <br />
        <br />
        <asp:Button ID="Button1" runat="server" Height="25px" OnClick="Button1_Click" Text="登录" Width="106px" />
    </div>
    </form>
</body>
</html>
