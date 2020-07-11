<%@ Page Language="C#" AutoEventWireup="true" CodeFile="upDoctor.aspx.cs" Inherits="upDoctor" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
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
            <td class="auto-style1">姓名：</td> <td class="auto-style1">
            <asp:Label ID="name" runat="server" Height="16px" Width="128px"></asp:Label>
            </td>
        </tr>

        <tr>
            <td>年龄：</td> <td>
            <asp:TextBox ID="age" runat="server"></asp:TextBox>
            </td>
        </tr>

        <tr>
            <td>职位：</td> <td>
            <asp:TextBox ID="job" runat="server"></asp:TextBox>
            </td>
        </tr>
        <tr>
            <td class="auto-style2">科室：</td> <td class="auto-style4">
            <asp:DropDownList ID="DropDownList2" runat="server">
                <asp:ListItem Value="儿科">儿科</asp:ListItem>
                <asp:ListItem Value="妇科">妇科</asp:ListItem>
                <asp:ListItem Value="内科">内科</asp:ListItem>
                <asp:ListItem Value="外科">外科</asp:ListItem>
                <asp:ListItem Value="放射科">放射科</asp:ListItem>
            </asp:DropDownList>
            </td>
        </tr>
        <tr>
            <td>
                <asp:HiddenField ID="HF" runat="server" OnValueChanged="HF_ValueChanged" />
            </td> <td>
                <asp:Button ID="Button1" runat="server" Height="31px" Text="保存" Width="98px" OnClick="Button1_Click" />
            </td>
        </tr>
    </table>
    </div>
    </form>
</body>
</html>
