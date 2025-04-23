/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_cmd_reject
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_hci_cmd_reject(int param_1,undefined4 param_2,undefined1 param_3,undefined1 *param_4)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  void *__s1;
  undefined2 auStack_22 [7];
  
  if (param_1 == 0) {
    uVar4 = 0x1101;
  }
  else {
    if (*(code **)(param_1 + 8) != (code *)0x0) {
      if (*(char *)(param_1 + 2) < '\0') {
        uVar1 = (**(code **)(param_1 + 8))(0,0,auStack_22,0);
        uVar1 = uVar1 & 0xff;
      }
      else {
        uVar1 = r_co_util_unpack(0,0,auStack_22,0xffff);
      }
      if (uVar1 == 0) {
        __s1 = *(void **)(param_1 + 8);
        iVar2 = memcmp(__s1,&_LC1,2);
        if (iVar2 == 0) {
          puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_2);
          *puVar3 = param_3;
          puVar3[2] = *param_4;
          puVar3[3] = param_4[1];
        }
        else {
          iVar2 = memcmp(__s1,&_LC2,3);
          if (iVar2 == 0) {
            puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101);
            *puVar3 = param_3;
            memcpy(puVar3 + 1,param_4,6);
          }
          else {
            puVar3 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_2,auStack_22[0]);
            *puVar3 = param_3;
          }
        }
        r_hci_send_2_host(puVar3);
      }
      else {
        r_assert_param(param_2,"hci_tl.c",0x1bf);
      }
      return;
    }
    uVar4 = 0x1102;
  }
  puVar3 = (undefined1 *)r_ke_msg_alloc(uVar4,0,param_2,1);
  *puVar3 = param_3;
  r_hci_send_2_host();
  return;
}

