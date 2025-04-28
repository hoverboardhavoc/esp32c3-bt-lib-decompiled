/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_dl_upd.o -> r_dl_upd_proc_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_dl_upd_proc_start(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  if ((*(short *)(iVar2 + 0x20) == *(short *)(iVar2 + 0x14)) &&
     (*(short *)(iVar2 + 0x22) == *(short *)(iVar2 + 0x18))) {
    return;
  }
  puVar3 = (undefined4 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x10a,param_1 << 8 | 1,0x14,*(code **)(_r_modules_funcs_p + 200));
  *(undefined1 *)(puVar3 + 1) = 7;
  (**(code **)(_r_ip_funcs_p + 0x684))(param_1,0,*(code **)(_r_ip_funcs_p + 0x684));
  *puVar3 = *(undefined4 *)(_r_ip_funcs_p + 0x5cc);
  *(undefined2 *)(puVar3 + 2) = *(undefined2 *)(iVar2 + 0x20);
  uVar1 = *(undefined2 *)(iVar2 + 0x22);
  *(undefined1 *)(puVar3 + 4) = 0;
  *(undefined2 *)((int)puVar3 + 10) = uVar1;
  puVar3[3] = 0x429000fb;
                    /* WARNING: Could not recover jumptable at 0x00010b50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xe0))(puVar3,*(code **)(_r_modules_funcs_p + 0xe0));
  return;
}

