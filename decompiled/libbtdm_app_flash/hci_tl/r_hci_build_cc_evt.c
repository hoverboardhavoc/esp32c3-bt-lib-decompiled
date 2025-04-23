/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_build_cc_evt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_hci_build_cc_evt(int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  undefined4 uVar5;
  char cVar6;
  short sStack_12;
  
  sVar1 = *(short *)(param_1 + 8);
  sStack_12 = *(short *)(param_1 + 10);
  iVar2 = r_hci_look_for_cmd_desc(sVar1);
  if ((iVar2 == 0) || (sStack_12 == 0)) {
    if (sVar1 != 0) {
      *(undefined1 *)(param_1 + 0xc) = 1;
      goto _L65;
    }
    uVar5 = 0x22a;
    uVar3 = 0;
    sVar4 = sStack_12;
  }
  else {
    if (*(code **)(iVar2 + 8) == (code *)0x0) {
      uVar3 = 4;
    }
    else {
      if (*(char *)(iVar2 + 2) < '\0') {
        uVar3 = (**(code **)(iVar2 + 8))(param_1 + 0xc,&sStack_12,sStack_12);
        uVar3 = uVar3 & 0xff;
      }
      else {
        uVar3 = r_co_util_pack(param_1 + 0xc,&sStack_12,sStack_12);
      }
      if (uVar3 == 0) goto _L65;
    }
    uVar5 = 0x220;
    sVar4 = sVar1;
  }
  r_assert_param(uVar3,sVar4,"hci_tl.c",uVar5);
_L65:
  *(undefined1 *)(param_1 + 7) = 0xe;
  *(char *)(param_1 + 8) = (char)sStack_12 + '\x03';
  cVar6 = hci_tl_env;
  if (hci_tl_env < '\0') {
    cVar6 = '\0';
  }
  *(char *)(param_1 + 10) = (char)sVar1;
  *(char *)(param_1 + 9) = cVar6;
  *(char *)(param_1 + 0xb) = (char)((ushort)sVar1 >> 8);
  return param_1 + 7;
}

