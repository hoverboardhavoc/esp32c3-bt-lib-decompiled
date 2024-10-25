/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> ke_msg.o -> r_ke_msg_alloc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * r_ke_msg_alloc(undefined2 param_1,undefined2 param_2,undefined2 param_3,size_t param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           (**(code **)(_r_modules_funcs_p + 0x120))
                     (param_4 + 0xc,2,*(code **)(_r_modules_funcs_p + 0x120));
  if (puVar1 == (undefined4 *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))("ke_msg.c",0x37,*(code **)(_r_plf_funcs_p + 8));
  }
  *(undefined2 *)(puVar1 + 1) = param_1;
  *(undefined2 *)((int)puVar1 + 6) = param_2;
  *(undefined2 *)(puVar1 + 2) = param_3;
  *(short *)((int)puVar1 + 10) = (short)param_4;
  *puVar1 = 0xffffffff;
  memset(puVar1 + 3,0,param_4);
  return puVar1 + 3;
}

