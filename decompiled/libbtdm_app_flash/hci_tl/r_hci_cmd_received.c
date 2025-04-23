/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  void *__s1;
  short asStack_22 [3];
  
  iVar5 = r_hci_look_for_cmd_desc();
  if (DAT_0001101d < '\0') {
    r_assert_err(0,"hci_tl.c",0x5fc);
  }
  if (param_1 != 0xc35) {
    DAT_0001101d = DAT_0001101d + -1;
  }
  if (iVar5 == 0) {
    param_3 = (ushort *)0x0;
    uVar8 = 1;
    iVar5 = 0;
    goto _L206;
  }
  if (DAT_0001101d < '\0') {
    param_3 = (ushort *)0x0;
    uVar8 = 7;
    goto _L206;
  }
  switch(*(byte *)(iVar5 + 2) & 0xf) {
  case 0:
  case 2:
    uVar3 = 0;
    break;
  case 1:
  case 3:
    if (param_2 < 2) {
_L173:
      if (param_1 == 0x406) {
        uVar1 = *param_3;
        r_hci_cmd_reject(iVar5,0x406,0,param_3);
        r_llc_hci_disconnected_dis((char)uVar1,0,(char)param_3[1]);
        return;
      }
      uVar8 = 2;
_L206:
      if (iVar5 == 0) {
        uVar9 = 0x1101;
      }
      else {
        if (*(code **)(iVar5 + 8) != (code *)0x0) {
          if (*(char *)(iVar5 + 2) < '\0') {
            uVar3 = (**(code **)(iVar5 + 8))(0,0,asStack_22,0);
            uVar3 = uVar3 & 0xff;
          }
          else {
            uVar3 = r_co_util_unpack(0,0,asStack_22,0xffff);
          }
          if (uVar3 == 0) {
            __s1 = *(void **)(iVar5 + 8);
            iVar5 = memcmp(__s1,&_LC1,2);
            if (iVar5 == 0) {
              puVar4 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_1);
              *puVar4 = uVar8;
              puVar4[2] = (char)*param_3;
              puVar4[3] = *(undefined1 *)((int)param_3 + 1);
            }
            else {
              iVar5 = memcmp(__s1,&_LC2,3);
              if (iVar5 == 0) {
                puVar4 = (undefined1 *)r_ke_msg_alloc(0x1101);
                *puVar4 = uVar8;
                memcpy(puVar4 + 1,param_3,6);
              }
              else {
                puVar4 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_1,asStack_22[0]);
                *puVar4 = uVar8;
              }
            }
            r_hci_send_2_host(puVar4);
          }
          else {
            r_assert_param(param_1,"hci_tl.c",0x1bf);
          }
          return;
        }
        uVar9 = 0x1102;
      }
      puVar4 = (undefined1 *)r_ke_msg_alloc(uVar9,0,param_1,1);
      *puVar4 = uVar8;
      r_hci_send_2_host();
      return;
    }
    uVar3 = (uint)*param_3;
    pbVar7 = (byte *)r_sdk_config_get_hl_derived_opts();
    if ((*pbVar7 <= uVar3) || ((&g_bt_plf_log_level)[uVar3] == '\0')) goto _L173;
    uVar3 = (uVar3 & 0xff) << 8 | 1;
    goto _L174;
  default:
    r_assert_param(param_1,"hci_tl.c",0x68e);
    return;
  case 8:
    uVar3 = 2;
    break;
  case 9:
    uVar3 = 3;
  }
  asStack_22[0] = 0;
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
_L174:
    asStack_22[0] = 0;
    if (*(code **)(iVar5 + 4) == (code *)0x0) {
      uVar2 = 4;
    }
    else {
      if ((*(byte *)(iVar5 + 2) & 0x40) == 0) {
        uVar2 = r_co_util_unpack();
      }
      else {
        uVar2 = (**(code **)(iVar5 + 4))(0,param_3,asStack_22,param_2);
        uVar2 = uVar2 & 0xff;
      }
      if (uVar2 == 1) {
        uVar9 = 0x12;
        goto _L205;
      }
    }
  }
  iVar6 = r_ke_msg_alloc(0x1105,uVar3,param_1,asStack_22[0]);
  if (uVar2 != 0) {
    r_assert_param(uVar2,param_1,"hci_tl.c",0x6ba);
  }
  if (iVar6 != 0) {
    if ((asStack_22[0] != 0) && (*(code **)(iVar5 + 4) != (code *)0x0)) {
      if ((*(byte *)(iVar5 + 2) & 0x40) == 0) {
        uVar2 = r_co_util_unpack();
      }
      else {
        uVar2 = (**(code **)(iVar5 + 4))(iVar6,param_3,asStack_22,param_2);
        uVar2 = uVar2 & 0xff;
      }
    }
    if (uVar2 != 0) {
      r_assert_param(uVar2,param_1,"hci_tl.c",0x6d2);
    }
    r_ke_msg_send(iVar6);
    return;
  }
  uVar9 = 7;
_L205:
  r_hci_cmd_reject(iVar5,param_1,uVar9,0);
  return;
}

