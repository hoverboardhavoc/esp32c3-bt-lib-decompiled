/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_evt_time_update_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_time_update_eco(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  uint uVar2;
  
  r_lld_con_evt_time_update();
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(char *)(iVar1 + 0x15) == '\0') {
    iVar1 = *(int *)(&lld_con_env + param_1 * 4);
    uVar2 = (uint)*(ushort *)(iVar1 + 0x88);
    if ((uint)*(ushort *)(iVar1 + 0x88) < (uint)*(ushort *)(iVar1 + 0x8a)) {
      uVar2 = (uint)*(ushort *)(iVar1 + 0x8a);
    }
    uVar2 = (uVar2 + 0x96 + (uint)*(ushort *)(&fixed_tx_time + (uint)*(byte *)(iVar1 + 0x93) * 2)) *
            2 + (uint)_sdk_cfg_priv_opts;
    if (uVar2 < 0x9c4) {
      uVar2 = 0x9c4;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x72c);
    *(uint *)(iVar1 + 0x5c) = uVar2;
    *(uint *)(iVar1 + 0x10) = uVar2;
                    /* WARNING: Could not recover jumptable at 0x00011608. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)
              (4,*(undefined1 *)(iVar1 + 0x8e),*(undefined4 *)(iVar1 + 100),uVar2 & 0xffff,0);
    return;
  }
  return;
}

