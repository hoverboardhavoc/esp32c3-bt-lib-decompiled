/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_count_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char r_lld_con_count_get(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = (int *)&lld_con_env;
  cVar1 = '\0';
  for (iVar4 = 0; iVar3 = r_sdk_config_get_opts(), iVar4 < (int)(uint)*(byte *)(iVar3 + 0xd);
      iVar4 = iVar4 + 1) {
    if (*piVar2 != 0) {
      cVar1 = cVar1 + '\x01';
    }
    piVar2 = piVar2 + 1;
  }
  return cVar1;
}

