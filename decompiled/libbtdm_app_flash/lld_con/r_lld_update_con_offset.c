/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_update_con_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_update_con_offset(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = (int *)&lld_con_env;
  for (uVar2 = 0; iVar3 = r_sdk_config_get_opts(), (int)uVar2 < (int)(uint)*(byte *)(iVar3 + 0xd);
      uVar2 = uVar2 + 1) {
    if (*piVar1 != 0) {
      iVar3 = r_llm_plan_elt_get(uVar2 & 0xff);
      if (iVar3 != 0) {
        uVar4 = r_lld_con_offset_get(uVar2 & 0xff);
        *(undefined4 *)(iVar3 + 8) = uVar4;
      }
    }
    piVar1 = piVar1 + 1;
  }
  return;
}

