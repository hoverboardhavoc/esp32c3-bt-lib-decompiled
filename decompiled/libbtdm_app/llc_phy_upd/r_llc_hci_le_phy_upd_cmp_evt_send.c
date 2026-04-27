/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llc_phy_upd.o -> r_llc_hci_le_phy_upd_cmp_evt_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_hci_le_phy_upd_cmp_evt_send
               (undefined2 param_1,undefined1 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (2 < (param_3 - 1U & 0xff)) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (param_3,0,"llc_phy_upd.c",0x36a,*(code **)(_r_plf_funcs_p + 0xc));
  }
  if (2 < (param_4 - 1U & 0xff)) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (param_4,0,"llc_phy_upd.c",0x36b,*(code **)(_r_plf_funcs_p + 0xc));
  }
  puVar2 = (undefined1 *)
           (**(code **)(_r_modules_funcs_p + 200))
                     (0x1104,param_1,0x3e,6,*(code **)(_r_modules_funcs_p + 200));
  *puVar2 = 0xc;
  puVar2[1] = param_2;
  iVar1 = _r_ip_funcs_p;
  puVar2[4] = (char)param_3;
  puVar2[5] = (char)param_4;
  *(undefined2 *)(puVar2 + 2) = param_1;
                    /* WARNING: Could not recover jumptable at 0x00010a8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x8c))(*(code **)(iVar1 + 0x8c));
  return;
}

