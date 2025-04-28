/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  uint uVar5;
  int iVar6;
  int extraout_a1;
  uint uVar7;
  
  uVar5 = r_rwip_time_get();
  uVar7 = extraout_a1 + 400;
  if (0x270 < uVar7) {
    uVar7 = extraout_a1 - 0xe1;
    uVar5 = uVar5 + 1 & 0xfffffff;
  }
  if (_sch_arb_env == 0) {
    r_rwip_timer_hus_set(0xffffffff,0);
    uVar4 = 0;
    uVar5 = 0xffffffff;
  }
  else {
    uVar3 = *(uint *)(_sch_arb_env + 8);
    uVar2 = *(int *)(_sch_arb_env + 4) - (uint)rwip_prog_delay & 0xfffffff;
    uVar4 = uVar7;
    if ((((uVar2 - uVar5 & 0xfffffff) < 0x7ffffff) &&
        (bVar1 = uVar2 == uVar5, uVar5 = uVar2, uVar4 = uVar3, bVar1)) && (uVar3 < uVar7)) {
      uVar4 = uVar7;
    }
    r_rwip_timer_hus_set(uVar5,uVar4);
  }
  iVar6 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar6 + 0x28) & 1) != 0) &&
     (iVar6 = r_sdk_config_get_opts_ext(), *(byte *)(iVar6 + 0x2c) < 2)) {
    r_ble_log_internal_x2(0x20040003,uVar5,uVar4);
    return;
  }
  return;
}

