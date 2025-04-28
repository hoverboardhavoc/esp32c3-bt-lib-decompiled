/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_build_le_evt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int r_hci_build_le_evt(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  ushort auStack_22 [7];
  
  auStack_22[0] = *(ushort *)(param_1 + 10);
  bVar1 = *(byte *)(param_1 + 0xc);
  if (bVar1 < 0xf0) {
    pcVar4 = *(code **)(_r_ip_funcs_p + 0x9c);
  }
  else {
    pcVar4 = *(code **)(_r_ip_funcs_p + 0xa0);
  }
  iVar2 = (*pcVar4)(bVar1,pcVar4);
  if (iVar2 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(bVar1,0,"hci_tl.c",0x2f8,*(code **)(_r_plf_funcs_p + 0xc));
    return param_1 + 10;
  }
  if (*(code **)(iVar2 + 4) == (code *)0x0) {
    uVar3 = 4;
  }
  else {
    if (*(char *)(iVar2 + 2) == '\0') {
      uVar3 = (**(code **)(_r_modules_funcs_p + 0x10))
                        (param_1 + 0xc,auStack_22,*(code **)(_r_modules_funcs_p + 0x10));
    }
    else {
      uVar3 = (**(code **)(iVar2 + 4))(param_1 + 0xc,auStack_22,auStack_22[0]);
      uVar3 = uVar3 & 0xff;
    }
    if (uVar3 == 0) goto _L96;
  }
  (**(code **)(_r_plf_funcs_p + 0xc))(uVar3,bVar1,"hci_tl.c",0x2eb,*(code **)(_r_plf_funcs_p + 0xc))
  ;
_L96:
  if (*(ushort *)(param_1 + 10) < auStack_22[0]) {
    (**(code **)(_r_plf_funcs_p + 0xc))(bVar1,"hci_tl.c",0x2ec,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (uVar3 == 0) {
    *(undefined1 *)(param_1 + 10) = 0x3e;
    *(char *)(param_1 + 0xb) = (char)auStack_22[0];
  }
  return param_1 + 10;
}

