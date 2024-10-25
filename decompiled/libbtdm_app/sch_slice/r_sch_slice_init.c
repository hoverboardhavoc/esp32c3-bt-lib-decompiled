/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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

