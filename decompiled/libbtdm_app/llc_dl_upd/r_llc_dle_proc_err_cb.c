/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_dl_upd.o -> r_llc_dle_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_dle_proc_err_cb(uint param_1,int param_2,char *param_3)

{
  int iVar1;
  char cVar2;
  
  if (param_2 == 1) {
    if (param_3[1] != '\x14') {
      return;
    }
    cVar2 = '\x19';
  }
  else {
    if (param_2 == 0) {
      cVar2 = *param_3;
    }
    else if (param_2 == 2) {
      cVar2 = param_3[1];
    }
    else {
      if (param_2 != 3) {
        return;
      }
      if (param_3[1] != '\x14') {
        return;
      }
      cVar2 = param_3[2];
    }
    if (cVar2 == '\0') {
      return;
    }
    if (1 < (byte)(cVar2 - 0x19U)) goto _L105;
  }
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((param_1 < *(byte *)(iVar1 + 0xd)) && (iVar1 = *(int *)(&llc_env + param_1 * 4), iVar1 != 0))
  {
    *(byte *)(iVar1 + 0x30) = *(byte *)(iVar1 + 0x30) & 0xdf;
  }
_L105:
                    /* WARNING: Could not recover jumptable at 0x000106d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x5d4))(param_1,cVar2);
  return;
}

