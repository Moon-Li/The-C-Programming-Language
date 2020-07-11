<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Upnumber.aspx.cs" Inherits="Upnumber" %>

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
        <asp:Label ID="Label1" runat="server" Font-Size="25pt" ForeColor="#CC33FF" Text="请输入挂号信息："></asp:Label>
        <br />
        <br />

    <table style="width:400px; margin:auto;">
        <tr>
            <td class="auto-style1">用户名：</td> <td class="auto-style1">
            <asp:Label ID="name" runat="server" Height="16px" Width="128px"></asp:Label>
            </td>
        </tr>

        <tr>
            <td>性别：</td> <td>
            <asp:Label ID="sex" runat="server" Height="16px" Width="128px"></asp:Label>
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
                &nbsp;</td>
        </tr>
    </table>
        <table style="width:400px; margin:auto;">
            <tr>
            <td>请输入病情描述：</td>
            </tr>

            <tr>                
            <td>
            <asp:TextBox ID="info" runat="server" Height="111px" Width="380px"></asp:TextBox>
            </td>
            </tr>
        </table>

        <br />
        <asp:Button ID="Button1" runat="server" Height="35px" Text="确认挂号" Width="97px" OnClick="Button1_Click" />
        <br />
        <br />

    </div>
    </form>
</body>
</html>
