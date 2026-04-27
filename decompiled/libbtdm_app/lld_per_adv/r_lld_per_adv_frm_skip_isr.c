/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_frm_skip_isr(uint param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar2 != 0) {
    if (1 < (byte)(*(char *)(iVar2 + 0x53) - 1U)) {
      (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x472,*(code **)(_r_plf_funcs_p + 8));
    }
    (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar2,1,*(code **)(_r_ip_funcs_p + 0x6b8));
    if (*(char *)(iVar2 + 0x53) == '\x02') {
      puVar3 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x208,0,0xff,2,*(code **)(_r_modules_funcs_p + 200));
      uVar1 = *(undefined1 *)(iVar2 + 0x52);
      puVar3[1] = 0;
      *puVar3 = uVar1;
      (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x2cc);
    }
    else {
      param_1 = (uint)*(byte *)(iVar2 + 0x52);
      *(char *)(iVar2 + 0x16) = *(char *)(iVar2 + 0x16) + rwip_priority;
      UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x300);
    }
                    /* WARNING: Could not recover jumptable at 0x000118c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1,UNRECOVERED_JUMPTABLE);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001190a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x48e,*(code **)(_r_plf_funcs_p + 8));
  return;
}

