/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_lld_con_start_eco(uint param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  DAT_0001584c = r_lld_read_clock();
  *(undefined2 *)(&DAT_00015804 + (param_1 + 0x10) * 2) = 0;
  r_lld_con_update_terminte_info_init(param_1);
  r_lld_con_llcp_ind_info_clear(param_1);
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x18) == '\0') {
    *(undefined1 *)(param_2 + 0x26) = 0;
  }
  iVar2 = r_lld_con_start(param_1,param_2);
  if (iVar2 == 0) {
    iVar3 = *(int *)(&lld_con_env + param_1 * 4);
    if (iVar3 != 0) {
      *(undefined2 *)(iVar3 + 0x98) = 0xffff;
      *(undefined4 *)(lld_con_fake_rx + param_1 * 4) = 0;
      if ((byte)(*(char *)(iVar3 + 0x93) - 2U) < 2) {
        if (0xb < param_1) {
          r_assert_err("lld_con.c",0x29bb);
        }
        puVar1 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar1 = *puVar1 & 0xfffffff0 | 0xe;
        if (0xb < param_1) {
          r_assert_err(0,"lld_con.c",0x295a);
        }
        *puVar1 = *puVar1 & 0xdfffffff | 0x20000000;
      }
    }
  }
  r_ble_log_internal_x1(0x400300fb,iVar2 << 0x10 | (uint)*(byte *)(param_2 + 0x24) << 8 | param_1);
  return iVar2;
}

