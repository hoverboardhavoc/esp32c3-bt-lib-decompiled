/*
 * Last changed at upstream commit 420ae1726dede6bbd4f3393744a8f3a252330b6a
 * https://github.com/espressif/esp32c3-bt-lib/commit/420ae1726dede6bbd4f3393744a8f3a252330b6a
 * Upstream date: 2022-09-16 21:21:40 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(421c2790)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_evt_time_update_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_time_update_hack(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  r_lld_con_evt_time_update();
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  iVar1 = _r_ip_funcs_p;
  if (*(char *)(iVar2 + 0x15) == '\0') {
    iVar2 = *(int *)(&lld_con_env + param_1 * 4);
    uVar3 = (uint)*(ushort *)(iVar2 + 0x88);
    if ((uint)*(ushort *)(iVar2 + 0x88) < (uint)*(ushort *)(iVar2 + 0x8a)) {
      uVar3 = (uint)*(ushort *)(iVar2 + 0x8a);
    }
    uVar3 = (uVar3 + 0x96 +
            (uint)*(ushort *)((int)&fixed_tx_time + (uint)*(byte *)(iVar2 + 0x93) * 2)) * 2 +
            (uint)_sdk_cfg_priv_opts;
    *(uint *)(iVar2 + 0x5c) = uVar3;
    *(uint *)(iVar2 + 0x10) = uVar3;
                    /* WARNING: Could not recover jumptable at 0x00010b6e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(iVar1 + 0x72c))
              (4,*(undefined1 *)(iVar2 + 0x8e),*(undefined4 *)(iVar2 + 100),uVar3 & 0xffff,0);
    return;
  }
  return;
}

