/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_task.o -> lld_test_end_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_test_end_ind_handler(undefined1 *param_1)

{
  undefined1 *puVar1;
  code *pcVar2;
  
  puVar1 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1101,0,0x201f,4,*(code **)(_r_modules_funcs_p + 200));
  *puVar1 = *param_1;
  pcVar2 = *(code **)(_r_ip_funcs_p + 0x8c);
  *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(param_1 + 2);
  (*pcVar2)(pcVar2);
  return 0;
}

