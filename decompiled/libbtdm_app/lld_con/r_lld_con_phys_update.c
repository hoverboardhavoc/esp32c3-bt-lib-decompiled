/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_phys_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_phys_update(int param_1,int param_2,undefined1 param_3,undefined2 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 0x46) == '\0') {
      *(undefined1 *)(iVar2 + 0x46) = 3;
      *(undefined2 *)(iVar2 + 0x44) = param_4;
      *(char *)(iVar2 + 0x34) = (char)param_2;
      *(undefined1 *)(iVar2 + 0x35) = param_3;
      uVar1 = 0;
      if (*(ushort *)(&byte_tx_time + (uint)*(byte *)(iVar2 + 0x94) * 2) <
          *(ushort *)(&byte_tx_time + param_2 * 2)) {
        (**(code **)(_r_ip_funcs_p + 0x3c4))
                  (*(undefined4 *)(iVar2 + 100),*(code **)(_r_ip_funcs_p + 0x3c4));
      }
      goto _L825;
    }
    (**(code **)(_r_plf_funcs_p + 0xc))
              (*(char *)(iVar2 + 0x46),0,"lld_con.c",0x10dd,*(code **)(_r_plf_funcs_p + 0xc));
  }
  uVar1 = 0xc;
_L825:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

