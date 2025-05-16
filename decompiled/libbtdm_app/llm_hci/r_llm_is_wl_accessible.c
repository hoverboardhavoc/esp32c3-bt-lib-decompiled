/*
 * Last changed at upstream commit b0ccea3c26a049649d2fdbaca78318af90a6dd5b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b0ccea3c26a049649d2fdbaca78318af90a6dd5b
 * Upstream date: 2025-05-16 11:55:10 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(4713205)
 * Source: libbtdm_app -> llm_hci.o -> r_llm_is_wl_accessible
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_is_wl_accessible(void)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  
  uVar1 = 0;
  do {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(byte *)(iVar2 + 0xd) <= uVar1) {
      return 1;
    }
    piVar4 = (int *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44);
    cVar3 = (char)piVar4[0x10];
    if ((byte)(cVar3 - 2U) < 2) {
      cVar3 = *(char *)(*piVar4 + 0x13);
_L335:
      if (cVar3 != '\0') {
        return 0;
      }
    }
    else {
      if (cVar3 == '\a') {
        cVar3 = *(char *)(*piVar4 + 1);
        goto _L335;
      }
      if (cVar3 == '\x05') {
        cVar3 = *(char *)*piVar4;
        goto _L335;
      }
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while( true );
}

