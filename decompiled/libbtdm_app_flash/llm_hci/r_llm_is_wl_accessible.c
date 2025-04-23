/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_hci.o -> r_llm_is_wl_accessible
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
    iVar2 = r_sdk_config_get_opts();
    if (*(byte *)(iVar2 + 0xd) <= uVar1) {
      return 1;
    }
    piVar4 = (int *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44);
    cVar3 = (char)piVar4[0x10];
    if ((byte)(cVar3 - 2U) < 2) {
      cVar3 = *(char *)(*piVar4 + 0x13);
_L208:
      if (cVar3 != '\0') {
        return 0;
      }
    }
    else {
      if (cVar3 == '\a') {
        cVar3 = *(char *)(*piVar4 + 1);
        goto _L208;
      }
      if (cVar3 == '\x05') {
        cVar3 = *(char *)*piVar4;
        goto _L208;
      }
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while( true );
}

