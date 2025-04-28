/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_tl.o -> r_hci_build_evt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    (**(code **)(_r_plf_funcs_p + 0xc))(0,"hci_tl.c",0x24f,*(code **)(_r_plf_funcs_p + 0xc));
  }
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x98))(uVar2,*(code **)(_r_ip_funcs_p + 0x98));
  if (iVar3 == 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))(uVar2,0,"hci_tl.c",0x278,*(code **)(_r_plf_funcs_p + 0xc));
    return param_1 + 10;
  }
  if (*(code **)(iVar3 + 4) == (code *)0x0) {
    if (*(short *)(param_1 + 10) != 0) {
      uVar4 = 4;
      goto _L79;
    }
  }
  else {
    if (*(char *)(iVar3 + 2) == '\0') {
      uVar4 = (**(code **)(_r_modules_funcs_p + 0x10))
                        (param_1 + 0xc,&uStack_12,*(code **)(_r_modules_funcs_p + 0x10));
    }
    else {
      uVar4 = (**(code **)(iVar3 + 4))(param_1 + 0xc,&uStack_12,uStack_12);
      uVar4 = uVar4 & 0xff;
    }
    if (uVar4 != 0) {
_L79:
      (**(code **)(_r_plf_funcs_p + 0xc))(uVar2,"hci_tl.c",0x26b,*(code **)(_r_plf_funcs_p + 0xc));
      goto _L80;
    }
  }
  uVar4 = 0;
_L80:
  if (*(ushort *)(param_1 + 10) < uStack_12) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (uVar4,uVar2,"hci_tl.c",0x26e,*(code **)(_r_plf_funcs_p + 0xc));
  }
  *(char *)(param_1 + 10) = (char)uVar1;
  *(char *)(param_1 + 0xb) = (char)uStack_12;
  return param_1 + 10;
}

