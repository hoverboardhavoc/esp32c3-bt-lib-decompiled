/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_evt_time_update_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_time_update_eco(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  r_lld_con_evt_time_update();
  iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  iVar1 = _r_ip_funcs_p;
  if (*(char *)(iVar3 + 0x15) == '\0') {
    uVar4 = (uint)*(ushort *)(iVar2 + 0x88);
    if ((uint)*(ushort *)(iVar2 + 0x88) < (uint)*(ushort *)(iVar2 + 0x8a)) {
      uVar4 = (uint)*(ushort *)(iVar2 + 0x8a);
    }
    uVar4 = (uVar4 + 0x96 + (uint)*(ushort *)(&fixed_tx_time + (uint)*(byte *)(iVar2 + 0x93) * 2)) *
            2 + (uint)_sdk_cfg_priv_opts;
    if (uVar4 < 0x9c4) {
      uVar4 = 0x9c4;
    }
    *(uint *)(iVar2 + 0x5c) = uVar4;
    *(uint *)(iVar2 + 0x10) = uVar4;
                    /* WARNING: Could not recover jumptable at 0x00011608. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(iVar1 + 0x72c))
              (4,*(undefined1 *)(iVar2 + 0x8e),*(undefined4 *)(iVar2 + 100),uVar4 & 0xffff,0);
    return;
  }
  return;
}

