/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> sch_slice.o -> r_sch_slice_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_sch_slice_init(char param_1)

{
  int iVar1;
  undefined1 auStack_11 [5];
  
  if ((byte)(param_1 - 1U) < 2) {
    memset(&sch_slice_env,0,0x60);
    _sch_slice_params = 0xffffffff;
    auStack_11[0] = 2;
    iVar1 = (*_rwip_param)(0x17,auStack_11,&sch_slice_env,_rwip_param);
    if (iVar1 != 0) {
      _DAT_00011060 = 0x57e4;
    }
    _r_plf_funcs_p = _DAT_00011060;
    return;
  }
  return;
}

