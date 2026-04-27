/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> ll_connection_param_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ll_connection_param_req_handler(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  
  iVar2 = *(int *)(&llc_env + param_1 * 4);
  iVar3 = r_llc_proc_id_get(1);
  iVar6 = 0x24;
  if (iVar3 == 0) {
    iVar3 = r_llc_con_upd_param_in_range_hack
                      (param_1,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2),
                       *(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8));
    iVar6 = 0x1e;
    if (iVar3 != 0) {
      iVar3 = r_llm_le_evt_mask_check(5);
      iVar6 = 0x1a;
      if (iVar3 != 0) {
        if (*(ushort *)(param_2 + 2) < 0xb) {
          uVar5 = r_lld_con_count_get();
          if (1 < uVar5) {
            return 0x23;
          }
          if (*(char *)(iVar2 + 0x1c) == '\x03') {
            return 0x23;
          }
          if (*(char *)(iVar2 + 0x1d) == '\x03') {
            return 0x23;
          }
        }
        if (((*(ushort *)(iVar2 + 0x42) & 1) == 0) ||
           (iVar6 = r_llc_proc_collision_check(param_1,5), iVar6 == 0)) {
          puVar4 = (undefined4 *)r_ke_msg_alloc(0x10b,param_1 << 8 | 1,0x30);
          *(undefined1 *)(puVar4 + 1) = 5;
          r_llc_proc_state_set(param_1,7);
          *puVar4 = r_llc_rem_con_upd_proc_err_cb;
          *(undefined2 *)(puVar4 + 2) = *(undefined2 *)(param_2 + 2);
          *(undefined2 *)((int)puVar4 + 10) = *(undefined2 *)(param_2 + 4);
          *(undefined2 *)(puVar4 + 3) = *(undefined2 *)(param_2 + 6);
          *(undefined2 *)((int)puVar4 + 0xe) = *(undefined2 *)(param_2 + 8);
          *(undefined1 *)((int)puVar4 + 0x27) = *(undefined1 *)(param_2 + 10);
          *(undefined2 *)(puVar4 + 5) = *(undefined2 *)(param_2 + 0xc);
          *(undefined2 *)((int)puVar4 + 0x16) = *(undefined2 *)(param_2 + 0xe);
          *(undefined2 *)(puVar4 + 6) = *(undefined2 *)(param_2 + 0x10);
          *(undefined2 *)((int)puVar4 + 0x1a) = *(undefined2 *)(param_2 + 0x12);
          *(undefined2 *)(puVar4 + 7) = *(undefined2 *)(param_2 + 0x14);
          *(undefined2 *)((int)puVar4 + 0x1e) = *(undefined2 *)(param_2 + 0x16);
          uVar1 = *(undefined2 *)(param_2 + 0x18);
          *(undefined1 *)((int)puVar4 + 0x2d) = 0;
          *(undefined1 *)((int)puVar4 + 0x2e) = 0;
          *(undefined2 *)(puVar4 + 8) = uVar1;
          r_llc_proc_reg(param_1,1,puVar4);
          r_llc_rem_con_upd_proc_continue_hack(param_1,7,0);
          iVar6 = 0;
        }
      }
    }
  }
  return iVar6;
}

