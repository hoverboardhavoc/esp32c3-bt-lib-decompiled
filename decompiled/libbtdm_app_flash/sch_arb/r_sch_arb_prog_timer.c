/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> sch_arb.o -> r_sch_arb_prog_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_arb_prog_timer(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int extraout_a1;
  
  uVar3 = r_rwip_time_get();
  uVar2 = extraout_a1 + 400;
  if (0x270 < uVar2) {
    uVar2 = extraout_a1 - 0xe1;
    uVar3 = uVar3 + 1 & 0xfffffff;
  }
  if (_sch_arb_env == 0) {
    r_rwip_timer_hus_set(0xffffffff,0);
    uVar2 = 0;
    uVar3 = 0xffffffff;
  }
  else {
    uVar1 = *(int *)(_sch_arb_env + 4) - (uint)rwip_prog_delay & 0xfffffff;
    if (((uVar1 - uVar3 & 0xfffffff) < 0x7ffffff) &&
       ((uVar1 != uVar3 || (uVar3 = uVar1, uVar2 < *(uint *)(_sch_arb_env + 8))))) {
      uVar3 = uVar1;
      uVar2 = *(uint *)(_sch_arb_env + 8);
    }
    r_rwip_timer_hus_set(uVar3,uVar2);
  }
  iVar4 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar4 + 0x28) & 1) != 0) &&
     (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 2)) {
    r_ble_log_internal_x2(0x20040003,uVar3,uVar2);
    return;
  }
  return;
}

