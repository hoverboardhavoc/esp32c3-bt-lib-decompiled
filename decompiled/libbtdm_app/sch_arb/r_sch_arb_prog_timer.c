/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_arb.o -> r_sch_arb_prog_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_arb_prog_timer(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int extraout_a1;
  uint uVar4;
  uint uVar5;
  
  uVar2 = (**(code **)(_r_modules_funcs_p + 0x2c4))(*(code **)(_r_modules_funcs_p + 0x2c4));
  uVar5 = extraout_a1 + 400;
  if (0x270 < uVar5) {
    uVar5 = extraout_a1 - 0xe1;
    uVar2 = uVar2 + 1 & 0xfffffff;
  }
  if (_sch_arb_env == 0) {
    uVar2 = 0xffffffff;
    uVar4 = 0;
  }
  else {
    uVar3 = *(int *)(_sch_arb_env + 4) - (uint)rwip_prog_delay & 0xfffffff;
    uVar4 = uVar5;
    if ((((uVar3 - uVar2 & 0xfffffff) < 0x7ffffff) &&
        (uVar4 = *(uint *)(_sch_arb_env + 8), bVar1 = uVar3 == uVar2, uVar2 = uVar3, bVar1)) &&
       (uVar4 < uVar5)) {
      uVar4 = uVar5;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000103ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x2dc))(uVar2,uVar4,*(code **)(_r_modules_funcs_p + 0x2dc));
  return;
}

