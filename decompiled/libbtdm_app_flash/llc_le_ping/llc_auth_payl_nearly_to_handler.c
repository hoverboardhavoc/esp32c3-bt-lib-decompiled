/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_le_ping.o -> llc_auth_payl_nearly_to_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
llc_auth_payl_nearly_to_handler
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x20) == '\0') {
    return 0;
  }
  uVar3 = param_3 >> 8;
  iVar4 = *(int *)(&llc_env + uVar3 * 4);
  iVar2 = r_sdk_config_get_opts(param_1,param_2,param_4);
  if ((((uVar3 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + uVar3 * 4), iVar2 != 0)) &&
      ((*(byte *)(iVar2 + 0x44) & 3) != 3)) && ((*(ushort *)(iVar4 + 0x42) & 0x20) != 0)) {
    puVar1 = (undefined4 *)r_ke_msg_alloc(0x10c,param_3,8);
    *(undefined1 *)(puVar1 + 1) = 8;
    r_llc_proc_state_set(uVar3,0);
    *puVar1 = r_llc_le_ping_proc_err_cb;
    r_ke_msg_send(puVar1);
  }
  return 0;
}

