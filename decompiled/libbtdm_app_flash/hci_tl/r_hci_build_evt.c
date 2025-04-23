/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_build_evt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_hci_build_evt(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  ushort uStack_12;
  
  uStack_12 = *(ushort *)(param_1 + 10);
  uVar1 = *(ushort *)(param_1 + 8);
  uVar2 = uVar1 & 0xff;
  if (0xff < uVar1) {
    r_assert_param(0,"hci_tl.c",0x24f);
  }
  iVar3 = r_hci_look_for_evt_desc(uVar2);
  if (iVar3 == 0) {
    r_assert_param(uVar2,0,"hci_tl.c",0x278);
    return param_1 + 10;
  }
  if (*(code **)(iVar3 + 4) == (code *)0x0) {
    if (*(short *)(param_1 + 10) != 0) {
      uVar4 = 4;
      goto _L86;
    }
  }
  else {
    if (*(char *)(iVar3 + 2) == '\0') {
      uVar4 = r_co_util_pack();
    }
    else {
      uVar4 = (**(code **)(iVar3 + 4))(param_1 + 0xc,&uStack_12,uStack_12);
      uVar4 = uVar4 & 0xff;
    }
    if (uVar4 != 0) {
_L86:
      r_assert_param(uVar2,"hci_tl.c",0x26b);
      goto _L87;
    }
  }
  uVar4 = 0;
_L87:
  if (*(ushort *)(param_1 + 10) < uStack_12) {
    r_assert_param(uVar4,uVar2,"hci_tl.c",0x26e);
  }
  *(char *)(param_1 + 10) = (char)uVar1;
  *(char *)(param_1 + 0xb) = (char)uStack_12;
  return param_1 + 10;
}

