/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
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
  uint uVar5;
  
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  r_lld_con_evt_time_update();
  iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  iVar1 = _r_ip_funcs_p;
  if (*(char *)(iVar3 + 0x15) == '\0') {
    uVar5 = (uint)*(byte *)(iVar2 + 0x93);
    if (uVar5 == 3) {
      uVar5 = 2;
    }
    uVar4 = (uint)*(ushort *)(iVar2 + 0x88);
    if ((uint)*(ushort *)(iVar2 + 0x88) < (uint)*(ushort *)(iVar2 + 0x8a)) {
      uVar4 = (uint)*(ushort *)(iVar2 + 0x8a);
    }
    uVar5 = (uVar4 + 0x96 + (uint)*(ushort *)(&fixed_tx_time + uVar5 * 2)) * 2 +
            (uint)_sdk_cfg_priv_opts;
    if (uVar5 < 0x9c4) {
      uVar5 = 0x9c4;
    }
    *(uint *)(iVar2 + 0x5c) = uVar5;
    *(uint *)(iVar2 + 0x10) = uVar5;
                    /* WARNING: Could not recover jumptable at 0x000115a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(iVar1 + 0x72c))
              (4,*(undefined1 *)(iVar2 + 0x8e),*(undefined4 *)(iVar2 + 100),uVar5 & 0xffff,0,
               *(code **)(iVar1 + 0x72c));
    return;
  }
  return;
}

