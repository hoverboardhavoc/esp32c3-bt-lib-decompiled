/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_cmd_received
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_hci_cmd_received(uint param_1,uint param_2,ushort *param_3)

{
  ushort uVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  void *__s1;
  short asStack_22 [3];
  
  iVar4 = r_hci_look_for_cmd_desc();
  if (DAT_0001201d < '\0') {
    r_assert_err(0,"hci_tl.c",0x5fd);
  }
  if (param_1 != 0xc35) {
    DAT_0001201d = DAT_0001201d + -1;
  }
  r_ble_log_internal_x1(0x20270199,param_2 << 0x10 | param_1 | (int)DAT_0001201d << 0x18);
  if (iVar4 == 0) {
    param_3 = (ushort *)0x0;
    uVar8 = 1;
    iVar4 = 0;
    goto _L198;
  }
  if (DAT_0001201d < '\0') {
    param_3 = (ushort *)0x0;
    uVar8 = 7;
    goto _L198;
  }
  switch(*(byte *)(iVar4 + 2) & 0xf) {
  case 0:
  case 2:
    uVar2 = 0;
    break;
  case 1:
  case 3:
    if (1 < param_2) {
      uVar2 = (uint)*param_3;
      pbVar6 = (byte *)r_sdk_config_get_hl_derived_opts();
      if ((uVar2 < *pbVar6) && ((&g_bt_plf_log_level)[uVar2] != '\0')) {
        uVar2 = (uVar2 & 0xff) << 8 | 1;
        break;
      }
    }
    if (param_1 == 0x406) {
      uVar1 = *param_3;
      r_hci_cmd_reject(iVar4,0x406,0,param_3);
      r_llc_hci_disconnected_dis((char)uVar1,0,(char)param_3[1]);
      return;
    }
    uVar8 = 2;
_L198:
    if (iVar4 == 0) {
      uVar9 = 0x1101;
    }
    else {
      if (*(code **)(iVar4 + 8) != (code *)0x0) {
        if (*(char *)(iVar4 + 2) < '\0') {
          uVar2 = (**(code **)(iVar4 + 8))(0,0,asStack_22,0);
          uVar2 = uVar2 & 0xff;
        }
        else {
          uVar2 = r_co_util_unpack(0,0,asStack_22,0xffff);
        }
        if (uVar2 == 0) {
          __s1 = *(void **)(iVar4 + 8);
          iVar4 = memcmp(__s1,&_LC1,2);
          if (iVar4 == 0) {
            puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_1);
            *puVar3 = uVar8;
            puVar3[2] = (char)*param_3;
            puVar3[3] = *(undefined1 *)((int)param_3 + 1);
          }
          else {
            iVar4 = memcmp(__s1,&_LC2,3);
            if (iVar4 == 0) {
              puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101);
              *puVar3 = uVar8;
              memcpy(puVar3 + 1,param_3,6);
            }
            else {
              puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_1,asStack_22[0]);
              *puVar3 = uVar8;
            }
          }
          r_hci_send_2_host(puVar3);
        }
        else {
          r_assert_param(param_1,"hci_tl.c",0x1bf);
        }
        return;
      }
      uVar9 = 0x1102;
    }
    puVar3 = (undefined1 *)r_ke_msg_alloc(uVar9,0,param_1,1);
    *puVar3 = uVar8;
    r_hci_send_2_host();
    return;
  default:
    r_assert_param(param_1,"hci_tl.c",0x691);
    return;
  case 8:
    uVar2 = 2;
    break;
  case 9:
    uVar2 = 3;
  }
  asStack_22[0] = 0;
  if (param_2 == 0) {
    uVar5 = 0;
  }
  else if (*(code **)(iVar4 + 4) == (code *)0x0) {
    uVar5 = 4;
  }
  else {
    if ((*(byte *)(iVar4 + 2) & 0x40) == 0) {
      uVar5 = r_co_util_unpack();
    }
    else {
      uVar5 = (**(code **)(iVar4 + 4))(0,param_3,asStack_22,param_2 & 0xffff);
      uVar5 = uVar5 & 0xff;
    }
    if (uVar5 == 1) {
      uVar9 = 0x12;
      goto _L197;
    }
  }
  iVar7 = r_ke_msg_alloc(0x1105,uVar2,param_1,asStack_22[0]);
  if (uVar5 != 0) {
    r_assert_param(uVar5,param_1,"hci_tl.c",0x6bd);
  }
  if (iVar7 != 0) {
    if ((asStack_22[0] != 0) && (*(code **)(iVar4 + 4) != (code *)0x0)) {
      if ((*(byte *)(iVar4 + 2) & 0x40) == 0) {
        uVar5 = r_co_util_unpack();
      }
      else {
        uVar5 = (**(code **)(iVar4 + 4))(iVar7,param_3,asStack_22,param_2 & 0xffff);
        uVar5 = uVar5 & 0xff;
      }
    }
    if (uVar5 != 0) {
      r_assert_param(uVar5,param_1,"hci_tl.c",0x6d5);
    }
    r_ke_msg_send(iVar7);
    return;
  }
  uVar9 = 7;
_L197:
  r_hci_cmd_reject(iVar4,param_1,uVar9,0);
  return;
}

