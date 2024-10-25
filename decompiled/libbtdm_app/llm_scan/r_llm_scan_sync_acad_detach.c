/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_scan_sync_acad_detach
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_llm_scan_sync_acad_detach(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  uVar2 = 2;
  if (param_1 < *(byte *)(iVar1 + 0xd)) {
    uVar2 = 2;
    iVar1 = *(int *)(_p_llm_env + 8) + param_1 * 0x44;
    if (*(char *)(iVar1 + 0x40) == '\x0f') {
      *(undefined2 *)(iVar1 + 0x2a) = 0xff;
      uVar2 = 0;
    }
  }
  return uVar2;
}

