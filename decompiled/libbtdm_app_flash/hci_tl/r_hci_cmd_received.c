/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_cmd_received
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_hci_cmd_received(int param_1,uint param_2,ushort *param_3)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 uVar7;
  short asStack_22 [3];
  
  iVar3 = r_hci_look_for_cmd_desc();
  if (DAT_0001101d < '\0') {
    r_assert_err(0,"hci_tl.c",0x5fc);
  }
  if (param_1 != 0xc35) {
    DAT_0001101d = DAT_0001101d + -1;
  }
  if (iVar3 == 0) {
    param_3 = (ushort *)0x0;
    uVar7 = 1;
    iVar3 = 0;
    goto _L202;
  }
  if (-1 < DAT_0001101d) {
    switch(*(byte *)(iVar3 + 2) & 0xf) {
    case 0:
    case 2:
      uVar2 = 0;
      break;
    case 1:
    case 3:
      if (1 < param_2) {
        uVar2 = (uint)*param_3;
        pbVar5 = (byte *)r_sdk_config_get_hl_derived_opts();
        if ((uVar2 < *pbVar5) && ((&g_bt_plf_log_level)[uVar2] != '\0')) {
          uVar2 = (uVar2 & 0xff) << 8 | 1;
          break;
        }
      }
      if (param_1 == 0x406) {
        uVar1 = *param_3;
        r_hci_cmd_reject(iVar3,0x406,0,param_3);
        r_llc_hci_disconnected_dis((char)uVar1,0,(char)param_3[1]);
        return;
      }
      uVar7 = 2;
      goto _L202;
    default:
      r_assert_param(param_1,"hci_tl.c",0x68e);
      return;
    case 8:
      uVar2 = 2;
      break;
    case 9:
      uVar2 = 3;
    }
    asStack_22[0] = 0;
    if (param_2 == 0) {
      uVar4 = 0;
    }
    else if (*(code **)(iVar3 + 4) == (code *)0x0) {
      uVar4 = 4;
    }
    else {
      if ((*(byte *)(iVar3 + 2) & 0x40) == 0) {
        uVar4 = r_co_util_unpack();
      }
      else {
        uVar4 = (**(code **)(iVar3 + 4))(0,param_3,asStack_22,param_2 & 0xffff);
        uVar4 = uVar4 & 0xff;
      }
      if (uVar4 == 1) {
        param_3 = (ushort *)0x0;
        uVar7 = 0x12;
        goto _L202;
      }
    }
    iVar6 = r_ke_msg_alloc(0x1105,uVar2,param_1,asStack_22[0]);
    if (uVar4 != 0) {
      r_assert_param(uVar4,param_1,"hci_tl.c",0x6ba);
    }
    if (iVar6 != 0) {
      if ((asStack_22[0] != 0) && (*(code **)(iVar3 + 4) != (code *)0x0)) {
        if ((*(byte *)(iVar3 + 2) & 0x40) == 0) {
          uVar4 = r_co_util_unpack();
        }
        else {
          uVar4 = (**(code **)(iVar3 + 4))(iVar6,param_3,asStack_22,param_2 & 0xffff);
          uVar4 = uVar4 & 0xff;
        }
      }
      if (uVar4 != 0) {
        r_assert_param(uVar4,param_1,"hci_tl.c",0x6d2);
      }
      r_ke_msg_send(iVar6);
      return;
    }
  }
  param_3 = (ushort *)0x0;
  uVar7 = 7;
_L202:
  r_hci_cmd_reject(iVar3,param_1,uVar7,param_3);
  return;
}

