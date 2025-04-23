/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> sch_arb.o -> r_sch_arb_prog_timer
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
  uint uVar4;
  int iVar5;
  int extraout_a1;
  uint uVar6;
  
  uVar4 = r_rwip_time_get();
  uVar6 = extraout_a1 + 400;
  if (0x270 < uVar6) {
    uVar6 = extraout_a1 - 0xe1;
    uVar4 = uVar4 + 1 & 0xfffffff;
  }
  if (_sch_arb_env == 0) {
    r_rwip_timer_hus_set(0xffffffff,0);
    uVar3 = 0;
    uVar4 = 0xffffffff;
  }
  else {
    uVar2 = *(int *)(_sch_arb_env + 4) - (uint)rwip_prog_delay & 0xfffffff;
    uVar3 = uVar6;
    if ((((uVar2 - uVar4 & 0xfffffff) < 0x7ffffff) &&
        (uVar3 = *(uint *)(_sch_arb_env + 8), bVar1 = uVar2 == uVar4, uVar4 = uVar2, bVar1)) &&
       (uVar3 < uVar6)) {
      uVar3 = uVar6;
    }
    r_rwip_timer_hus_set(uVar4,uVar3);
  }
  iVar5 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar5 + 0x28) & 1) != 0) &&
     (iVar5 = r_sdk_config_get_opts_ext(), *(byte *)(iVar5 + 0x2c) < 2)) {
    r_ble_log_internal_x2(0x20040003,uVar4,uVar3);
    return;
  }
  return;
}

