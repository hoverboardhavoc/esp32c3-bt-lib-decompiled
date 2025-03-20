/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> llc_encrypt.o -> r_llc_loc_encrypt_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010382) */

void r_llc_loc_encrypt_proc_err_cb(uint param_1,int param_2,byte *param_3)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  
  if (param_2 == 1) {
    bVar3 = 0x1a;
  }
  else if (param_2 == 0) {
    bVar3 = *param_3;
  }
  else if (param_2 == 2) {
    bVar3 = param_3[1];
  }
  else {
    if (param_2 != 3) {
      r_assert_param("llc_encrypt.c",0x5ca);
      return;
    }
    if (param_3[1] == 3) {
      bVar3 = param_3[2];
    }
    else {
      bVar3 = 0x3d;
      if ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) == 0) {
        return;
      }
    }
  }
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  iVar1 = r_llc_proc_get(0);
  iVar2 = r_llc_proc_state_get();
  if (iVar2 == 9) {
    r_assert_param(param_1,9,"llc_encrypt.c",0x28b);
    return;
  }
  if (bVar3 == 0x13) goto _L27;
  if (bVar3 < 0x14) {
    if (bVar3 == 6) {
      if (iVar2 == 5) goto _L27;
      goto _L30;
    }
    bVar4 = 8;
_L53:
    if (bVar3 == bVar4) goto _L27;
  }
  else {
    if (bVar3 != 0x1a) {
      bVar4 = 0x22;
      goto _L53;
    }
_L30:
    if (iVar2 == 4) goto _L27;
  }
  r_llc_disconnect(param_1,0x3d,1);
  bVar3 = 0x3d;
_L27:
  iVar2 = r_sdk_config_get_opts();
  if (((param_1 < *(byte *)(iVar2 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    *(byte *)(iVar5 + 0x45) = *(byte *)(iVar5 + 0x45) & 0xf7;
    r_lld_con_data_flow_set(param_1,1);
    r_llc_llcp_state_set(param_1,2,0);
    r_llc_proc_timer_pause_set(param_1,1,0);
    *(ushort *)(iVar5 + 0x42) = *(ushort *)(iVar5 + 0x42) & 0xffdf | (ushort)(bVar3 == 0) << 5;
    r_llc_le_ping_restart(param_1);
  }
  r_llc_hci_enc_evt_send(param_1,bVar3,*(undefined1 *)(iVar1 + 0x3a));
  r_llc_proc_unreg(param_1,0);
  *(ushort *)(iVar5 + 0x42) = *(ushort *)(iVar5 + 0x42) & 0xfdff;
  return;
}

